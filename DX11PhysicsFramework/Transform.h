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
	Transform();
	~Transform();

	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }
	XMFLOAT3 GetPosition() const { return _position;  }

	void SetRotation(float x, float y, float z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }
	XMFLOAT3 GetRotation() const { return _rotation; }

	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }
	XMFLOAT3 GetScale() const { return _scale; }

};
