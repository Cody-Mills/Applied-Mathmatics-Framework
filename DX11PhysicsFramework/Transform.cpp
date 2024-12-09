#include "Transform.h"

void Transform::Move(XMFLOAT3 direction)
{
	_position.x += direction.x;
	_position.y += direction.y;
	_position.z += direction.z;
}
