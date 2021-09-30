#include "fpmas/model/model.h"

#define AGENT_TYPES Agent

class Agent : public fpmas::model::AgentBase<Agent> {
	public:
		void hello_world();

		static void to_json(nlohmann::json& json, const Agent* agent);
		static Agent* from_json(const nlohmann::json& json);
};
