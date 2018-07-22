#pragma once
#include "../../editor/editor.h"

namespace gloom {
	class scenario_view : public QGraphicsScene {
	public:
		scenario_view(editor& editor, scenario& scenario);

	private:
		void add_room_view(room& room);
		void remove_room_view(const room& room);
		
		void delete_selected();

		virtual void keyReleaseEvent(QKeyEvent *event) override;
		virtual void wheelEvent(QGraphicsSceneWheelEvent *event) override;

		editor& m_editor;
	};
}