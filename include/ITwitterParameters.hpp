#ifndef __I_TWITTER_PARAMETERS__
#define __I_TWITTER_PARAMETERS__

#include<vector>
#include<string>

namespace azha {
  class ITwitterParameters {
  public:
    virtual ~ITwitterParameters();
    std::string composeQueryString();
  protected:
    std::vector<std::pair<std::string, std::string>> queries;
  };
}

#endif // __I_TWITTER_PARAMETERS__
