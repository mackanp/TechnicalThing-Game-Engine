#include "RenderEngine.h"

RenderEngine::RenderEngine()
{
    const GLfloat vertices[] = {
        0, 0.5f, 0,
        -0.5f, -0.5f, 0,
        0.5f, -0.5f, 0
    };

    const GLfloat texture_coords[] = {
        0, 0, 0,
        0, 0, 0,
        0, 0, 0
    };

    const GLfloat colors[] = {
        1, 0, 0, 1,
        0, 1, 0, 1,
        0, 0, 1, 1
    };

    glGenBuffers(1, &v_id);
    glBindBuffer(GL_ARRAY_BUFFER, v_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * sizeof(GLfloat), vertices, GL_DYNAMIC_DRAW);

    glGenBuffers(1, &t_id);
    glBindBuffer(GL_ARRAY_BUFFER, t_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texture_coords) * sizeof(GLfloat), texture_coords, GL_DYNAMIC_DRAW);

    glGenBuffers(1, &c_id);
    glBindBuffer(GL_ARRAY_BUFFER, c_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors) * sizeof(GLfloat), colors, GL_DYNAMIC_DRAW);

    vector<unsigned int> indices;
    for (int i = 0; (unsigned int)i < (sizeof(vertices) * sizeof(GLfloat)); i++)
        indices.push_back(i);

    glGenBuffers(1, &i_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    draw_count = (indices.size() * sizeof(unsigned int));
}

void RenderEngine::updateVertices(vector<GLfloat> vertices)
{

}

void RenderEngine::updateTextureCoords(vector<GLfloat> texture_coords)
{

}

void RenderEngine::updateColors(vector<GLfloat> colors)
{

}

void RenderEngine::render(bool useTextures)
{
    if (useTextures)
        glEnable(GL_TEXTURE_2D);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    if (useTextures)
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, v_id);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    if (useTextures)
    {
        glBindBuffer(GL_ARRAY_BUFFER, t_id);
        glTexCoordPointer(3, GL_FLOAT, 0, 0);
    }

    glBindBuffer(GL_ARRAY_BUFFER, c_id);
    glColorPointer(3, GL_FLOAT, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_id);
    glDrawElements(GL_TRIANGLES, draw_count, GL_UNSIGNED_INT, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    if (useTextures)
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    if (useTextures)
        glDisable(GL_TEXTURE_2D);
}

RenderEngine::~RenderEngine()
{
    //dtor
}
