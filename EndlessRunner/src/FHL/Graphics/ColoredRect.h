#ifndef FHL_COLOREDRECT_H
#define FHL_COLOREDRECT_H

#include <GL/glew.h>

#include <FHL/Graphics/Renderable.h>
#include <FHL/Graphics/Vao.h>
#include <FHL/Graphics/Transformable.h>
#include <FHL/Graphics/Sizeable.h>
#include <FHL/Graphics/Vertex.h>
#include <FHL/Graphics/Litable.h>
#include <FHL/Graphics/UsingShader.h>

namespace fhl
{
	class ResMgr;

	class ColoredRect :
		public Transformable,
		public internal::Sizeable,
		public UsingShader,
		public Renderable,
		public Litable
	{
		friend class ResMgr;

	public:
		explicit ColoredRect(Vec2f _size, Color _color = Color::Transparent);

	public:
		void setColor(const Color & _color) { m_color = _color; }
		const Color & getColor() const { return m_color; }

		void render(const RenderConf & _conf) const override;

	private:
		void setUp();

	private:
		Color m_color;

		constexpr static const char * simpleShaderName = "_FHL_rectSimpleShader";
		constexpr static const char * lightShaderName = "_FHL_rectLightShader";
	};

}

#endif // FHL_COLOREDRECT_H