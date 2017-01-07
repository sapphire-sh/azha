#ifndef __OAUTH_H__
#define __OAUTH_H__

#include <string>
#include <unordered_map>

#include "TwitterParameters.hpp"

namespace azha {
	class OAuth {
	public:
		OAuth(std::string _consumer_key, std::string _consumer_secret);
		OAuth(std::string _consumer_key, std::string _consumer_secret, std::string _access_token, std::string _access_token_secret);
		
		OAuth& oauth_callback(const std::string& _oauth_callback) {
			parameters["oauth_callback"] = _oauth_callback;
			return *this;
		}
		OAuth& oauth_consumer_key(const std::string& _oauth_consumer_key) {
			parameters["oauth_consumer_key"] = _oauth_consumer_key;
			return *this;
		}
		OAuth& oauth_consumer_secret(const std::string& _oauth_consumer_secret) {
			parameters["oauth_consumer_secret"] = _oauth_consumer_secret;
			return *this;
		}
		OAuth& oauth_nonce(const std::string& _oauth_nonce) {
			parameters["oauth_nonce"] = _oauth_nonce;
			return *this;
		}
		OAuth& oauth_signature(const std::string& _oauth_signature) {
			parameters["oauth_signature"] = _oauth_signature;
			return *this;
		}
		OAuth& oauth_signature_method(const std::string& _oauth_signature_method) {
			parameters["oauth_signature_method"] = _oauth_signature_method;
			return *this;
		}
		OAuth& oauth_timestamp(const uint64_t _oauth_timestamp) {
			parameters["oauth_timestamp"] = std::to_string(_oauth_timestamp);
			return *this;
		}
		OAuth& oauth_token(const std::string& _oauth_token) {
			parameters["oauth_token"] = _oauth_token;
			return *this;
		}
		OAuth& oauth_token_secret(const std::string& _oauth_token_secret) {
			parameters["oauth_token_secret"] = _oauth_token_secret;
			return *this;
		}
		OAuth& oauth_verifier(const std::string& _oauth_verifier) {
			parameters["oauth_verifier"] = _oauth_verifier;
			return *this;
		}
		OAuth& oauth_version(const std::string& _oauth_version) {
			parameters["oauth_version"] = _oauth_version;
			return *this;
		}
		
		const std::string& oauth_callback() {
			return parameters["oauth_callback"];
		}
		const std::string& oauth_consumer_key() {
			return parameters["oauth_consumer_key"];
		}
		const std::string& oauth_consumer_secret() {
			return parameters["oauth_consumer_secret"];
		}
		const std::string& oauth_nonce() {
			return parameters["oauth_nonce"];
		}
		const std::string& oauth_signature() {
			return parameters["oauth_signature"];
		}
		const std::string& oauth_signature_method() {
			return parameters["oauth_signature_method"];
		}
		const uint64_t oauth_timestamp() {
			return std::stoull(parameters["oauth_timestamp"]);
		}
		const std::string& oauth_token() {
			return parameters["oauth_token"];
		}
		const std::string& oauth_token_secret() {
			return parameters["oauth_token_secret"];
		}
		const std::string& oauth_verifier() {
			return parameters["oauth_verifier"];
		}
		const std::string& oauth_version() {
			return parameters["oauth_version"];
		}
		
		const std::string header_string(Parameters::ITwitterParameters& parameters);
	private:
		std::unordered_map<std::string, std::string> parameters;
		
		const std::string generate_nonce();
		const uint64_t generate_timestamp();
		const std::string calculate_signature(Parameters::ITwitterParameters& parameters);
		
		const std::string parameter_string(Parameters::ITwitterParameters& parameters);
		const std::string signature_base_string(Parameters::ITwitterParameters& parameters);
		const std::string signing_key();
	};
}

#endif // __OAUTH_H__
