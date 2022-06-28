#pragma once

namespace HeaderFiles::Helpers
{
	class Exception : public exception
	{
	protected:
		string _message;
		const char* _time;

	public:

		Exception(const char* message = "Unknown Message", const char* time = "") noexcept;


		const char* what() const override;


	};

	Exception::Exception(const char* message, const char* time) noexcept
		: exception(message), _time(time)
	{
		_message = "Message: " + (string)exception::what() + "\nTime: " + _time;
	}


	const char* Exception::what() const
	{
		return _message.c_str();
	}

}


