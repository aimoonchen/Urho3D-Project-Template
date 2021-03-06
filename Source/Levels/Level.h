#pragma once

#include <Urho3D/Scene/SplinePath.h>
#include <Urho3D/Graphics/Terrain.h>
#include <Urho3D/Graphics/Zone.h>
#include "../BaseLevel.h"
#include "Player/Player.h"

namespace Levels {
    class Level : public BaseLevel
    {
        URHO3D_OBJECT(Level, BaseLevel);

    public:
        /// Construct.
        Level(Context* context);

        virtual ~Level();
        void HandlePhysicsPrestep(StringHash eventType, VariantMap& eventData);
        void HandlePostUpdate(StringHash eventType, VariantMap& eventData);
        void HandlePostRenderUpdate(StringHash eventType, VariantMap& eventData);

    protected:
        virtual void Init () override;

    private:
        void CreateScene();

        void CreateUI();

        void SubscribeToEvents();
        void UnsubscribeToEvents();

        void StartAudio();
        void StopAllAudio();

        void HandleKeyDown(StringHash eventType, VariantMap& eventData);
        void HandleKeyUp(StringHash eventType, VariantMap& eventData);
        void HandleWindowClosed(StringHash eventType, VariantMap& eventData);

        void HandleControllerConnected(StringHash eventType, VariantMap& eventData);
        void HandleControllerDisconnected(StringHash eventType, VariantMap& eventData);

        void HandleVideoSettingsChanged(StringHash eventType, VariantMap& eventData);

        bool _showScoreboard;

        bool _drawDebug;

        HashMap<int, SharedPtr<Player>> _players;

        SharedPtr<Terrain> _terrain;

        SharedPtr<Zone> _defaultZone;
    };
}