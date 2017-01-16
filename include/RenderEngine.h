#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include <vector>

#include <GL/glew.h>

using namespace std;


class RenderEngine
{
    public:
        RenderEngine();
        ~RenderEngine();

        void updateVertices(vector<GLfloat> vertices);
        void updateTextureCoords(vector<GLfloat> texture_coords);
        void updateColors(vector<GLfloat> colors);
        void render(bool useTextures);

    protected:
        GLuint v_id;
        GLuint t_id;
        GLuint c_id;

        GLuint i_id;

        int draw_count;

    private:
};

#endif // RENDERENGINE_H
