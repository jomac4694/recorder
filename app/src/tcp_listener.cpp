#include "tcp_listener.h"
#include <boost/asio.hpp>
#include <boost/asio/high_resolution_timer.hpp>
#include "global_logger.h"

TcpListener::TcpListener(const uint16_t port, const std::string& name) : 
    mPort(port),
    mName(name)
{

}

TcpListener::~TcpListener()
{
    mListenThread = std::thread();
}

void SendHandler(boost::system::error_code ex)
{
    LOG("[Server] Doing send handler")
}

std::string read_(boost::asio::ip::tcp::socket & socket) {
       boost::asio::streambuf buf;
       boost::asio::read_until( socket, buf, "\n" );
       std::string data = boost::asio::buffer_cast<const char*>(buf.data());
       data.erase(std::remove(data.begin(), data.end(), '\n'), data.cend());
       return data;
}

void TcpListener::Listen()
{
    while (true)
    {
    boost::asio::io_service io_service;
//listen for new connection
      boost::asio::ip::tcp::acceptor acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), mPort ));
//socket creation 
      boost::asio::ip::tcp::socket socket_(io_service);
//waiting for connection
      acceptor_.accept(socket_);
//read operation
      std::string message = read_(socket_);
      LOG(mName + " Got Message: " + message);
      auto t1 = std::shared_ptr<TestEvent>(new TestEvent());
      t1->SetField(EventName::INT32_FIELD, 500);
      t1->SetField(EventName::DOUBLE_FIELD, 50.55);
      t1->SetField(EventName::STRING_FIELD, message);
      SendEvent(t1);
    }
}

void TcpListener::Activate()
{
    mListenThread = std::thread(std::bind(&TcpListener::Listen, this));
}