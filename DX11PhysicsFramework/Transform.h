#include <directxmath.h>
#include <d3d11_1.h>
#include <string>


using namespace DirectX;
using namespace std;

class Transform {
private:
	XMFLOAT3 _position;
	XMFLOAT3 _rotation;
	XMFLOAT3 _scale;

public:
	void SetPosition(XMFLOAT3 position) { _position = position; }
	XMFLOAT3 GetPosition() const { return _position; }

	void SetRotation(XMFLOAT3 rotation) { _rotation = rotation; }
	XMFLOAT3 GetRotation() const { return _rotation; }

	void SetScale(XMFLOAT3 scale) { _scale = scale; }
	XMFLOAT3 GetScale() const { return _scale; }

	void Move(XMFLOAT3 direction);
};
