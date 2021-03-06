#ifndef MODM_GES_PAINTER_HPP
#define MODM_GES_PAINTER_HPP

#include "surface.hpp"
#include "pixel_color.hpp"
#include <xpcc/ui/animation/interpolation.hpp>
#include <xpcc/math/utils/misc.hpp>

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/rect.hpp"
#include "geometry/circle.hpp"

namespace modm
{

namespace ges
{

template< PixelFormat Format >
class Painter
{
public:
	using SpecificSurface= Surface<Format>;
	using NativeColor = typename SpecificSurface::NativeColor;
	using AlphaColor = typename NativeColor::AlphaColor;

	using CompositionOperator = void (NativeColor::*)(const AlphaColor &color);

public:
	// native composition operators
	static constexpr CompositionOperator Clear = &NativeColor::Clear;

	static constexpr CompositionOperator A = &NativeColor::A;
	static constexpr CompositionOperator B = &NativeColor::B;

	static constexpr CompositionOperator AoverB = &NativeColor::AoverB;
	static constexpr CompositionOperator BoverA = &NativeColor::BoverA;

	static constexpr CompositionOperator AinB = &NativeColor::AinB;
	static constexpr CompositionOperator BinA = &NativeColor::BinA;

	static constexpr CompositionOperator AoutB = &NativeColor::AoutB;
	static constexpr CompositionOperator BoutA = &NativeColor::BoutA;

	static constexpr CompositionOperator AatopB = &NativeColor::AatopB;
	static constexpr CompositionOperator BatopA = &NativeColor::BatopA;

	static constexpr CompositionOperator Xor = &NativeColor::Xor;
	static constexpr CompositionOperator Plus = &NativeColor::Plus;

public:
	Painter(SpecificSurface &surface) :
		surface(surface) {}


	inline void
	drawLine(const Line &line, const AlphaColor &color, Rect clip)
	{ drawLine(line, color, A, clip); }

	void
	drawLine(const Line &line, const AlphaColor &color, CompositionOperator composition = A, Rect clip = Rect());


	inline void
	drawRect(const Rect &rectangle, const AlphaColor &color, Rect clip)
	{ drawRect(rectangle, color, A, clip); }

	void
	drawRect(const Rect &rectangle, const AlphaColor &color, const CompositionOperator composition = A, Rect clip = Rect());


	inline void
	fillRect(const Rect &rectangle, const AlphaColor &color, Rect clip)
	{ fillRect(rectangle, color, A, clip); }

	void
	fillRect(const Rect &rectangle, const AlphaColor &color, const CompositionOperator composition = A, Rect clip = Rect());


	inline void
	drawCircle(const Circle &circle, const AlphaColor &color, Rect clip)
	{ drawCircle(circle, color, A, clip); }

	void
	drawCircle(const Circle &circle, const AlphaColor &color, const CompositionOperator composition = A, Rect clip = Rect());


	inline void
	fillCircle(const Circle &circle, const AlphaColor &color, Rect clip)
	{ fillCircle(circle, color, A, clip); }

	void
	fillCircle(const Circle &circle, const AlphaColor &color, const CompositionOperator composition = A, Rect clip = Rect());


	inline void
	drawEllipse(const Ellipse &ellipse, const AlphaColor &color, Rect clip)
	{ drawEllipse(ellipse, color, A, clip); }

	void
	drawEllipse(const Ellipse &ellipse, const AlphaColor &color, const CompositionOperator composition = A, Rect clip = Rect());


	inline void
	fillEllipse(const Ellipse &ellipse, const AlphaColor &color, Rect clip)
	{ fillEllipse(ellipse, color, A, clip); }

	void
	fillEllipse(const Ellipse &ellipse, const AlphaColor &color, const CompositionOperator composition = A, Rect clip = Rect());


protected:
	inline void
	drawEvenEllipse(const Ellipse &ellipse, const AlphaColor &color, const CompositionOperator composition, const Rect &clip);

	inline void
	drawOddEllipse(const Ellipse &ellipse, const AlphaColor &color, const CompositionOperator composition, const Rect &clip);

	inline void
	fillEvenEllipse(const Ellipse &ellipse, const AlphaColor &color, const CompositionOperator composition, const Rect &clip);

	inline void
	fillOddEllipse(const Ellipse &ellipse, const AlphaColor &color, const CompositionOperator composition, const Rect &clip);


protected:
	inline void
	drawHorizontalLineClipped(int16_t y, int16_t beginX, int16_t endX, const Rect &clip,
							  const AlphaColor &color, const CompositionOperator composition);

	inline void
	drawVerticalLineClipped(int16_t x, int16_t beginY, int16_t endY, const Rect &clip,
							  const AlphaColor &color, const CompositionOperator composition);


protected:
	inline void
	drawHorizontalLine(int16_t y, int16_t beginX, int16_t endX,
					   const AlphaColor &color, const CompositionOperator composition);

	inline void
	drawVerticalLine(int16_t x, int16_t beginY, int16_t endY,
					 const AlphaColor &color, const CompositionOperator composition);

private:
	SpecificSurface &surface;
};

// native composition operator defintions
template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::Clear;

template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::A;
template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::B;

template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::AoverB;
template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::BoverA;

template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::AinB;
template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::BinA;

template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::AoutB;
template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::BoutA;

template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::AatopB;
template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::BatopA;

template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::Xor;
template< PixelFormat Format > constexpr typename Painter<Format>::CompositionOperator Painter<Format>::Plus;

} // namespace ges

} // namespace modm

#include "painter_impl.hpp"

#endif // MODM_GES_PAINTER_HPP

