#include <iostream>

#include "azha.hpp"

int main() {
	std::string consumer_key = "IQKbtAYlXLripLGPWd0HUA";
	std::string consumer_secret = "GgDYlkSvaPxGxC4X8liwpUoqKwwr3lCADbz8A7ADU";
	
	auto azha = new azha::TwitterClient(consumer_key, consumer_secret);
	
//	azha::Parameters::Statuses::UpdateParameters p;
//	p.status("hello, world!");
//	
//	azha->request(p, nullptr);
	
	azha->request_token(nullptr);
	
	return 0;
}

