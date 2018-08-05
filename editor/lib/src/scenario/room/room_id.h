#pragma once

namespace gloom {
	enum class room_id {
		a1a, a1b, a2a, a2b, a3a, a3b, a4a, a4b,
		b1a, b1b, b2a, b2b, b3a, b3b, b4a, b4b,
		c1a, c1b, c2a, c2b,
		d1a, d1b, d2a, d2b,
		e1a, e1b,
		f1a, f1b,
		g1a, g1b, g2a, g2b,
		h1a, h1b, h2a, h2b, h3a, h3b,
		i1a, i1b, i2a, i2b,
		j1a, j1b, j2a, j2b,
		k1a, k1b, k2a, k2b,
		l1a, l1b, l2a, l2b, l3a, l3b,
		m1a, m1b,
		n1a, n1b,
		unknown
	};

	inline QString get_id_string(room_id id) {
		static const QStringList id_names{
			"a1a", "a1b", "a2a", "a2b", "a3a", "a3b", "a4a", "a4b",
			"b1a", "b1b", "b2a", "b2b", "b3a", "b3b", "b4a", "b4b",
			"c1a", "c1b", "c2a", "c2b",
			"d1a", "d1b", "d2a", "d2b",
			"e1a", "e1b",
			"f1a", "f1b",
			"g1a", "g1b", "g2a", "g2b",
			"h1a", "h1b", "h2a", "h2b", "h3a", "h3b",
			"i1a", "i1b", "i2a", "i2b",
			"j1a", "j1b", "j2a", "j2b",
			"k1a", "k1b", "k2a", "k2b",
			"l1a", "l1b", "l2a", "l2b", "l3a", "l3b",
			"m1a", "m1b",
			"n1a", "n1b"
		};

		return id_names[static_cast<int>(id)];
	}

	inline room_id get_id(const QString& id) {
		static const QStringList id_names{
			"a1a", "a1b", "a2a", "a2b", "a3a", "a3b", "a4a", "a4b",
			"b1a", "b1b", "b2a", "b2b", "b3a", "b3b", "b4a", "b4b",
			"c1a", "c1b", "c2a", "c2b",
			"d1a", "d1b", "d2a", "d2b",
			"e1a", "e1b",
			"f1a", "f1b",
			"g1a", "g1b", "g2a", "g2b",
			"h1a", "h1b", "h2a", "h2b", "h3a", "h3b",
			"i1a", "i1b", "i2a", "i2b",
			"j1a", "j1b", "j2a", "j2b",
			"k1a", "k1b", "k2a", "k2b",
			"l1a", "l1b", "l2a", "l2b", "l3a", "l3b",
			"m1a", "m1b",
			"n1a", "n1b"
		};

		return static_cast<room_id>(id_names.indexOf(id));
	}

	enum class room_style {
		stone, wood, earth, cave
	};

	inline room_style get_style(const QString& style) {
		static const QStringList style_names{
			"stone", "wood", "earth", "cave"
		};

		return static_cast<room_style>(style_names.indexOf(style));
	}

	inline QString get_style_name(room_style style) {
		static const QStringList style_names{
			"stone", "wood", "earth", "cave"
		};

		return style_names[static_cast<int>(style)];
	}
}