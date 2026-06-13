#pragma once

namespace DollsEngine
{
	template<typename T>
	constexpr size_t GetEventTypeId()
	{
		static char typeIdPlaceholder = 0;
		return reinterpret_cast<size_t>(&typeIdPlaceholder);
	}

	class Event
	{
	public:
		virtual size_t GetEventTypeId() const = 0;
	};
}