#include <iostream>

#include "azha.hpp"

int main() {
	std::string consumer_key = "bFGL1R2mLMdlknzEZEuEKqwlk";
	std::string consumer_secret = "DqpROputhQlx2wuiDbANEgB893dDxm61ZNHAyNUz9pYZkbG6kF";
	std::string access_token = "529303031-xj47mpDMUk3G3DSjg8kKqMG6rVd86b5PoJP8A9Tg";
	std::string access_token_secret = "Gq2x1X1te2YuDZttc7NMEZkm0HfgZxe4a7ldbg4xMsL6D";
	
	auto azha = new azha::TwitterClient(consumer_key, consumer_secret, access_token, access_token_secret);
	
	azha::Parameters::Statuses::UpdateParameters p("hello, world!");
	
	azha->POST(p, nullptr);
	
	return 0;
}

