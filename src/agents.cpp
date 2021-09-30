#include "agents.h"

void Agent::hello_world() {
	std::cout << "[" << this->model()->graph().getMpiCommunicator().getRank()
		<< "] Hello World" << std::endl;
}

void Agent::to_json(nlohmann::json& json, const Agent* agent) {

}

Agent* Agent::from_json(const nlohmann::json& json) {
	return new Agent;
}
