#include "fpmas.h"
#include "agents.h"

using fpmas::synchro::GhostMode;
using fpmas::synchro::HardSyncMode;

FPMAS_JSON_SET_UP(AGENT_TYPES)

FPMAS_DEFINE_GROUPS(Group1, Group2)

int main(int argc, char** argv) {
	FPMAS_REGISTER_AGENT_TYPES(AGENT_TYPES)
	fpmas::init(argc, argv);
	{
		// Defines a default model
		fpmas::model::Model<HardSyncMode> model;

		// Defines an agent group
		fpmas::model::Behavior<Agent> hello_world(&Agent::hello_world);
		fpmas::model::AgentGroup& group = model.buildGroup(Group1, hello_world);
		group.add(new Agent);
		
		// Set up agents and other groups
		// ...

		// Schedules load balancing
		model.scheduler().schedule(0, 10, model.loadBalancingJob());

		// Schedules agent group execution
		model.scheduler().schedule(0, 1, group.jobs());
		// Schedules other jobs
		// ...
		
		// Runs the model for 2 iterations
		model.runtime().run(2);
	}
	fpmas::finalize();
}
