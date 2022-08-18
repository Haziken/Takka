#pragma once 

#include "Buffer.h"

namespace Takka
{
	class UBO : public virtual Buffer
	{
	public: 
		UBO() noexcept;
		UBO(const UBO& ubo) noexcept;
		UBO(UBO&& ubo) noexcept;

		UBO& operator=(const UBO& ubo) noexcept;
		UBO& operator=(UBO&& ubo) noexcept;
	};
}