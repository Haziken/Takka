#include "../../include/Video/UBO.h"

Takka::UBO::UBO() noexcept : Buffer(GL_UNIFORM_BUFFER) {}

Takka::UBO::UBO(const UBO& ubo) noexcept : Buffer(ubo) {}

Takka::UBO::UBO(UBO&& ubo) noexcept : Buffer(std::move(ubo)) {}

Takka::UBO& Takka::UBO::operator=(const UBO& ubo) noexcept
{
	BufferCopyData(ubo, *this);
	return *this;
}

Takka::UBO& Takka::UBO::operator=(UBO&& ubo) noexcept
{
	Swap(ubo, *this);
	return *this;
}
