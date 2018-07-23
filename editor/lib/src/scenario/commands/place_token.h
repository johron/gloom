#pragma once

namespace gloom {
	namespace commands {
		class place_token : public QUndoCommand {
		public:
			place_token()
				: QUndoCommand("place token") { }

			virtual void redo() override {

			}

			virtual void undo() override {

			}
		};
	}

	class remove_token : public QUndoCommand {
	public:
		remove_token()
			: QUndoCommand("remove token") { }
			
		virtual void redo() override {

		}

		virtual void undo() override {

		}
	};
}