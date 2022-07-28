#include <iostream>
#include <cpr/cpr.h>

int main() {
    std::string strUrl = "http://httpbin.org/html";
    cpr::Response response = cpr::Get(cpr::Url{strUrl}, cpr::Header({{"accept", "text/html"}}));

    auto textHeaderStart = response.text.find("<h1>");
    auto textHeaderEnd = response.text.find("</h1>");
    int textHeaderSize = static_cast<int>(textHeaderEnd - textHeaderStart - 4);

    std::cout << response.text.substr(textHeaderStart + 4, textHeaderSize);
}
