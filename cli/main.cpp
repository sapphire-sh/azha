#include <iostream>

#include "azha.hpp"

int main() {
	std::string consumer_key = "bFGL1R2mLMdlknzEZEuEKqwlk";//IQKbtAYlXLripLGPWd0HUA";
	std::string consumer_secret = "DqpROputhQlx2wuiDbANEgB893dDxm61ZNHAyNUz9pYZkbG6kF";//GgDYlkSvaPxGxC4X8liwpUoqKwwr3lCADbz8A7ADU";
	
	azha::Client::instance().consumer_key(consumer_key, consumer_secret);
	
//	azha::parameters::OAuth::RequestTokenParameters request_token_param;
//	request_token_param.oauth_callback("oob");
//	const auto &request_token_response = azha::Client::instance().request(request_token_param).get();
//	
//	std::cout << "https://twitter.com/oauth/authorize?oauth_token=" << request_token_response.at("oauth_token") << std::endl;
//	
//	azha::Client::instance().access_token(request_token_response.at("oauth_token"), "");
//	
//	std::string oauth_verifier;
//	std::cin >> oauth_verifier;
//	
//	azha::parameters::OAuth::AccessTokenParameters access_token_param;
//	access_token_param.oauth_verifier(oauth_verifier);
//	const auto &access_token_response = azha::Client::instance().request(access_token_param).get();
//
//	for(const auto &response_key_val : access_token_response) {
//		std::cout << response_key_val.first << " " << response_key_val.second << std::endl;
//	}
//
//	azha::Client::instance().access_token(access_token_response.at("oauth_token"), access_token_response.at("oauth_token_secret"));
	
	azha::Client::instance().access_token("529303031-ze9rALRIGgbxhyM8gwB9plIuhlqehosuXDmMlXNZ", "vz6fXJDTNpLw5rfS1fhndkc8KSXLoxJBtdt06BA3HqOMH");

	azha::parameters::POST::Statuses::UpdateParameters update_param;
	update_param.status("");
	const auto &status_response = azha::Client::instance().request(update_param).get();

	std::cout << "ended" << std::endl;

	return 0;
}

