#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Transform.h"
#include "Appearance.h"

using namespace DirectX;
using namespace std;



class GameObject
{
public:
	GameObject(string type, Appearance* appearance);
	~GameObject();

	string GetType() const { return _type; }

	void SetParent(GameObject * parent) { _parent = parent; }

	// Rendering information
	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }
	void Move(XMFLOAT3 direction);
	void Update(float dt);
	void Draw(ID3D11DeviceContext * pImmediateContext);
	Transform* GetTransform() { return _transform; }
	Appearance* GetAppearance() { return _appearance; }

private:
	GameObject* _parent = nullptr;

	string _type;
	XMFLOAT4X4 _world;

	Transform* _transform = new Transform;
	Appearance* _appearance;
};

