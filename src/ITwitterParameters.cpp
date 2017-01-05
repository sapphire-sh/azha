#include "ITwitterParameters.hpp"

namespace azha {
  std::string ITwitterParameters::composeQueryString() {
    std::string queryString;
    return (queryString.size() > 0 ? "?" + queryString : "");
  }
}
