#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance)
{
	_parent = nullptr;
	_appearance->GetTextureRV();
}

GameObject::~GameObject()
{
	_parent = nullptr;
}

void GameObject::Update(float dt)
{
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_transform->GetScale().x, _transform->GetScale().y, _transform->GetScale().z);
	XMMATRIX rotation = XMMatrixRotationX(_transform->GetRotation().x) * XMMatrixRotationY(_transform->GetRotation().y) * XMMatrixRotationZ(_transform->GetRotation().z);
	XMMATRIX translation = XMMatrixTranslation(_transform->GetPosition().x, _transform->GetPosition().y, _transform->GetPosition().z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}
}

void GameObject::Move(XMFLOAT3 direction)
{
	//NEEDS += to be an UPDATE
	_transform->SetPosition((_transform->GetPosition().x + direction.x), (_transform->GetPosition().y + direction.y), (_transform->GetPosition().z + direction.z));

}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_appearance->Draw(pImmediateContext);
}
