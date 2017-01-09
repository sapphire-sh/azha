#include <iostream>

#include "azha.hpp"

void request_token_callback(const int code, const std::unordered_map<std::string, std::string>& response) {
//	std::cout << response << std::endl;
}

int main() {
	std::string consumer_key = "IQKbtAYlXLripLGPWd0HUA";
	std::string consumer_secret = "GgDYlkSvaPxGxC4X8liwpUoqKwwr3lCADbz8A7ADU";
	
	auto azha = new azha::azha(consumer_key, consumer_secret);
	
//	azha::Parameters::Statuses::UpdateParameters p;
//	p.status("hello, world!");
//	
//	azha->request(p, nullptr);
	
	azha->client()->request_token(request_token_callback);
	
	return 0;
}

