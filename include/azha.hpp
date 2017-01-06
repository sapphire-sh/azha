#ifndef __AZHA_H__
#define __AZHA_H__

#include<functional>

#include "TwitterParameters.hpp"

namespace azha {
  class Account;

  enum class RequestType {
    GET,
    POST
  };

  namespace Request {
	  void sendRequest(RequestType requestType,\
					   const std::string &endpoint,\
					   const Parameters::ITwitterParameters &parameters,\
					   const std::function<void(const int code, const std::string &ret)>);
  }
}

#endif //__AZHA_H__
