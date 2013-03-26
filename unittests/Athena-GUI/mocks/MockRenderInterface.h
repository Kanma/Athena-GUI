#ifndef _MOCKRENDERINTERFACE_H_
#define _MOCKRENDERINTERFACE_H_

#include <Rocket/Core/RenderInterface.h>

using namespace Rocket::Core;


class MockRenderInterface : public RenderInterface
{
public:
    MockRenderInterface()
    {
    }

    virtual ~MockRenderInterface()
    {
    }

    virtual void RenderGeometry(Vertex* vertices, int num_vertices, int* indices,
                                int num_indices, TextureHandle texture,
                                const Vector2f& translation)
    {
    }

    virtual void EnableScissorRegion(bool enable)
    {
    }

    virtual void SetScissorRegion(int x, int y, int width, int height)
    {
    }
};

#endif
