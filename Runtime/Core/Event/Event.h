#pragma once

#include <iostream>

namespace DollsEngine
{
	template<typename T>
	constexpr size_t GetEventTypeId()
	{
		static const size_t typeId = reinterpret_cast<size_t>(&typeId);
		return typeId;
	}

	class Event
	{
	public:
		virtual size_t GetEventTypeId() const = 0;
	};
}