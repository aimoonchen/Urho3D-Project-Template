#pragma once

#include <Urho3D/UI/UIElement.h>
#include "../BaseLevel.h"

namespace Levels {

    class Credits : public BaseLevel
    {
        URHO3D_OBJECT(Credits, BaseLevel);

	public:
        /// Construct.
        Credits(Context* context);

        virtual ~Credits();

    protected:
        void Init () override;

    private:

        void CreateScene();

        /**
         * Create the actual Credits content
         */
        void CreateUI();


        void SubscribeToEvents();

        /**
         * End credits
         */
        void HandleEndCredits(bool forced = false);

        UIElement* CreateEmptyLine(int height);

        /**
         * Create single text line
         */
		void CreateSingleLine(String content, int fontSize);

		/**
		 * Create single image line
		 */
		void CreateImageLine(const String& image, int size);

		/**
		 * Handle credits scrolling
		 */
		void HandleUpdate(StringHash eventType, VariantMap& eventData);

		/**
		 * Credits window lifetime timer
		 */
        Timer _timer;

        /**
         * Credits view content
         */
		Vector<SharedPtr<UIElement>> _credits;

		/**
		 * Credits base UI view
		 */
		SharedPtr<UIElement> _creditsBase;

		float _offset;
    };
}