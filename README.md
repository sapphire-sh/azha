# azha
azha is a pure C++ Twitter library.

## Installation
Copy project directory into your own project directory.

## Usage
#### Consumer Key Setup:
```c++
std::string consumer_key = "";
std::string consumer_secret = "";

azha::Client::instance().consumer_key(consumer_key, consumer_secret);
```

#### OAuth Authorization:
```c++
azha::parameters::POST::OAuth::RequestTokenParameters request_token_parameters;
request_token_parameters.oauth_callback("oob");
const auto &request_token_response = azha::Client::instance().request(request_token_parameters);

std::cout << "https://twitter.com/oauth/authorize?oauth_token=" << request_token_response.at("oauth_token") << std::endl;

azha::Client::instance().access_token(request_token_response.at("oauth_token"), "");

std::string oauth_verifier;
std::cin >> oauth_verifier;

azha::parameters::OAuth::AccessTokenParameters access_token_parameters;
access_token_parameters.oauth_verifier(oauth_verifier);
const auto &access_token_response = azha::Client::instance().request(access_token_parameters).get();

azha::Client::instance().access_token(access_token_response.at("oauth_token"), access_token_response.at("oauth_token_secret"));
```

#### Access Token Setup:
```c++
std::string access_token = "";
std::string access_token_secret = "";
azha::Client::instance().access_token(access_token, access_token_secret);
```

#### Get HomeTimeline:
```c++
azha::parameters::GET::Statuses::HomeTimelineParameters p;
const auto &res = azha::Client::instance().request(p).get();
```

#### Status Update:
```c++
azha::parameters::POST::Statuses::UpdateParameters p;
p.status("hello, world!");
const auto &res = azha::Client::instance().request(p).get();
```

## License
See the `LICENSE` file for details.
