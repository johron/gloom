#pragma once

namespace util {
	class graphics_view_zoom : public QObject {
		Q_OBJECT
	public:
		graphics_view_zoom(QGraphicsView* view);
		void gentle_zoom(double factor);
		void set_modifiers(Qt::KeyboardModifiers modifiers);
		void set_zoom_factor_base(double value);

	private:
		QGraphicsView* _view;
		Qt::KeyboardModifiers _modifiers;
		double _zoom_factor_base;
		QPointF target_scene_pos, target_viewport_pos;
		bool eventFilter(QObject* object, QEvent* event);

	signals:
		void zoomed();
	};
}