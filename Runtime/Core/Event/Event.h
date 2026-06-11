#pragma once

template<typename T>
constexpr size_t GetEventTypeId()
{
	static char typeIdPlaceHolder = 0;
	return reinterpret_cast<size_t>(&typeIdPlaceHolder);
}

class Event
{
public:
};