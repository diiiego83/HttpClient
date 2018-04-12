/*

 * Copyright (c) 2018 Diego Molteni, moltediego@gmail.com
 * SPDX-License-Identifier: MIT 

*/

#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <memory>
#include <vector>

namespace httpclient {

enum class HTTP_STATUS { OK, CLIENT_ERROR, HTTP_ERROR };

class HTTPClient {

public:

    HTTPClient();
    HTTPClient(const HTTPClient & rhs) = delete;
    HTTPClient& operator = (const HTTPClient& rhs) = delete;
    ~HTTPClient();

    void url(const std::string& url);
    void user_agent(const std::string& user_agent);

    void set_response_buffer(std::vector<char>* response_buffer);
    std::vector<char> get_resonse_buffer() const;

    bool ok() const;
    bool is_http_error() const;
    bool is_client_error() const;
    HTTP_STATUS status() const;
    uint64_t status_code() const;
    std::string status_message() const;
    void raise_for_status() const;
    void raise_for_http_status() const;
    void raise_for_client_status() const;

    void send();

private:

    class HTTPClientIMPL;
    std::unique_ptr<HTTPClientIMPL> _impl;

};

} // namespace httpclient

#endif