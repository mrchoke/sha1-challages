#include <iostream>
#include <sstream>
#include <boost/uuid/detail/sha1.hpp>

std::string hexstr(u_int * d)
{
  std::stringstream s;
  for (std::size_t i=0; i<5; i++)
    s << std::hex << d[i];
  return s.str();
}

int main() {
  std::string msg = "clubhouse";
  long int rounds = 5555555555;
  unsigned int hash[5];
  boost::uuids::detail::sha1 sha1;

  for (std::size_t i=0; i<rounds; i++)
  {
    sha1.reset();
    sha1.process_bytes(msg.c_str(), msg.length());
    sha1.get_digest(hash);
    msg=hexstr(hash);
  }

  std::cout << msg << std::endl;
}
