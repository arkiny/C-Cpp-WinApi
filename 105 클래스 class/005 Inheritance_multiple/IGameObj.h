
class IGameObject
{
public:
	IGameObject();
	virtual ~IGameObject();
	virtual void SendEvent() = 0;	// "=0" part makes this method pure virtual, and
									// also makes this class abstract.

private:

};

IGameObject::IGameObject()
{
}

IGameObject::~IGameObject()
{
}