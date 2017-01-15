# azha

[![Build Status](https://travis-ci.org/sapphiredev/azha.svg?branch=master)](https://travis-ci.org/sapphiredev/azha)

azha is a pure C++ Twitter library.

## Installation
Copy project directory into your own project directory.

## Usage
#### Instantiation
```c++
auto client = new azha::Client();
```

#### Consumer Key Setup:
```c++
std::string consumer_key = "";
std::string consumer_secret = "";

client->consumer_key(consumer_key, consumer_secret);
```

#### Access Token Setup:
```c++
std::string access_token = "";
std::string access_token_secret = "";
client->access_token(access_token, access_token_secret);
```

#### OAuth Authorization:
```c++
azha::parameters::POST::OAuth::RequestTokenParameters request_token_parameters;
request_token_parameters.oauth_callback("oob");
const auto &request_token_response = client->request(request_token_parameters);

std::cout << "https://twitter.com/oauth/authorize?oauth_token=" << request_token_response.at("oauth_token") << std::endl;

client->access_token(request_token_response.at("oauth_token"), "");

std::string oauth_verifier;
std::cin >> oauth_verifier;

azha::parameters::OAuth::AccessTokenParameters access_token_parameters;
access_token_parameters.oauth_verifier(oauth_verifier);
const auto &access_token_response = client->request(access_token_parameters).get();

client->access_token(access_token_response.at("oauth_token"), access_token_response.at("oauth_token_secret"));
```

#### Get HomeTimeline:
```c++
azha::parameters::GET::Statuses::HomeTimelineParameters p;
const auto &res = client->request(p).get();
```

#### Status Update:
```c++
azha::parameters::POST::Statuses::UpdateParameters p;
p.status("hello, world!");
const auto &res = client->request(p).get();
```

## License
See the `LICENSE` file for details.
