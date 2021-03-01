/**
 * @file splash.cpp
 * Creates a splash screen
 */


//
// Copyright (c) 2008-2020 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//



#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>

#include <Urho3D/Urho3D.h>
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Graphics/RenderPath.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/UI/UIEvents.h>
#include <Urho3D/UI/Window.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Geometry.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/DebugRenderer.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Skybox.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/Audio/Sound.h>
#include <Urho3D/Audio/SoundSource3D.h>
#include <Urho3D/Audio/SoundListener.h>
#include <Urho3D/Audio/Audio.h>
#include <Urho3D/Graphics/ParticleEmitter.h>
#include <Urho3D/Graphics/ParticleEffect.h>
#include <Urho3D/Graphics/Terrain.h>

#include "splash.h"

#include <Urho3D/DebugNew.h>

// Expands to this example's entry-point
URHO3D_DEFINE_APPLICATION_MAIN(HelloWorld)

HelloWorld::HelloWorld(Context* context) :
    Sample(context)
{
}

void HelloWorld::Start()
{
    // Execute base class startup
    Sample::Start();

    // Create "Hello World" Text
    CreateText();
    
    // Set the mouse mode to use in the sample
    Sample::InitMouseMode(MM_FREE);
}

void HelloWorld::CreateText()
{
    auto* ui = GetSubsystem<UI>();
    UIElement* root = ui->GetRoot();
    auto* cache = GetSubsystem<ResourceCache>();
    // Load the style sheet from xml
    root->SetDefaultStyle(cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
    
    auto* startButton = CreateButton
    (root, "StartButton", "StartText", "Start Game!", 400, 500);
    
    // Construct new Text object
    SharedPtr<Text> helloText(new Text(context_));

    // Set String to display
    helloText->SetText("Welcome to Sound Pirates!");

    // Set font and text color
    helloText->SetFont(cache->GetResource<Font>("Fonts/Anonymous Pro.ttf"), 30);
    helloText->SetColor(Color(0.0f, 10.0f, 1.0f));

    // Align Text center-screen
    helloText->SetHorizontalAlignment(HA_CENTER);
    helloText->SetVerticalAlignment(VA_CENTER);
    helloText->AddTag("welcomeText");

    // Add Text instance to the UI root element
    GetSubsystem<UI>()->GetRoot()->AddChild(helloText);
    SubscribeToEvent(startButton, E_CLICK, URHO3D_HANDLER(HelloWorld, HandleStartClick));
}

/**
 * Creates a button on the given root, with the given tag.
 * It also adds a text to the button given a name with txtName, and a content with txtCont.
 * It will place the button according to x and y coordinates.
 * Possible hAlign values = HA_LEFT, HA_CENTER, HA_RIGHT, HA_CUSTOM
 * Possible vAlign values =  VA_TOP = 0, VA_CENTER, VA_BOTTOM, VA_CUSTOM 
 * 
 */ 
Button* HelloWorld::CreateButton
(UIElement* root, String tag, String txtName, String txtCont, 
  int x, int y)
{
    auto* b = new Button(context_);
    
    root->AddChild(b);
    // Reference a style from the style sheet loaded earlier:
    b->SetStyleAuto();
    
    b->SetMinWidth(250);
    
    b->AddTag(tag);
    b->SetPosition(IntVector2(x, y));

    // Set the layout mode to make the child text elements aligned vertically
    b->SetLayout(LM_VERTICAL, 20, {40, 40, 40, 40});    
    
    // Add text
    b->CreateChild<Text>(txtName)->SetStyleAuto();
    auto* t = b->GetChildStaticCast<Text>(txtName, false);
    t->SetText(txtCont);
    t->SetHorizontalAlignment(HA_CENTER);
    
    return b;
}

void HelloWorld::SubscribeToEvents()
{
    // Subscribe HandleUpdate() function for processing update events
    SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(HelloWorld, HandleUpdate));
    
}

void HelloWorld::HandleUpdate(StringHash eventType, VariantMap& eventData)
{
   using namespace Update;

    // Take the frame time step, which is stored as a float
    float timeStep = eventData[P_TIMESTEP].GetFloat();

    // Move the camera, scale movement with time step
    MoveCamera(timeStep);
}

/** 
 * when you click on the start button, the UI elements dissapear
 * 
 */
void HelloWorld::HandleStartClick(StringHash eventType, VariantMap& eventData)
{
    using namespace Click;
    
    UIElement* root = GetSubsystem<UI>()->GetRoot();
    auto* cache = GetSubsystem<ResourceCache>();
    
    // erase welcome text
    Urho3D::PODVector<Urho3D::UIElement*> welcomeText = root->GetChildrenWithTag("welcomeText");
    welcomeText[0]->SetVisible(false);
    
    // erase button
    auto* element = (Button*)eventData[P_ELEMENT].GetVoidPtr();
    element->SetVisible(false);
    
    //Show the main game screen
    CreateScene();
    SetupViewport();

    // Finally subscribe to the update event so we can move the camera.
    SubscribeToEvents();    
}

/** 
 * when you click on the closer button, the ship moves closer to you (the camera)
 * 
 */
void HelloWorld::HandleCloserClick(StringHash eventType, VariantMap& eventData)
{
    using namespace Click;
    PODVector<Urho3D::Node*> ship = scene_->GetChildrenWithTag("ship");
    Vector3 shipPos = ship[0]->GetPosition();
    Vector3 cameraPos = cameraNode_->GetPosition();
    float x = shipPos.x_ - cameraPos.x_;
    float y = shipPos.y_ - cameraPos.y_;
    float z = shipPos.z_ - cameraPos.z_;
    //if(x > 0 && y > 0 && z > 0)
    //{
        Vector3* newPos = new Vector3(shipPos.x_-1, shipPos.y_-1, shipPos.z_-1);
        ship[0]->SetPosition(*newPos);
    //}
}

/** 
 * when you click on the closer button, the ship moves closer to you (the camera)
 * 
 */
void HelloWorld::HandleFurtherClick(StringHash eventType, VariantMap& eventData)
{
    using namespace Click;
    PODVector<Urho3D::Node*> ship = scene_->GetChildrenWithTag("ship");
    Vector3 shipPos = ship[0]->GetPosition();
    Vector3 cameraPos = cameraNode_->GetPosition();
    float x = shipPos.x_ - cameraPos.x_;
    float y = shipPos.y_ - cameraPos.y_;
    float z = shipPos.z_ - cameraPos.z_;
    //if(x > 0 && y > 0 && z > 0)
    //{
        Vector3* newPos = new Vector3(shipPos.x_+1, shipPos.y_+1, shipPos.z_+1);
        ship[0]->SetPosition(*newPos);
      
}

/**
 * Creates the scene with the ship
 * 
 * 
 */ 
void HelloWorld::CreateScene()
{
    auto* cache = GetSubsystem<ResourceCache>();
    scene_ = new Scene(context_);

    // Create the Octree component to the scene. This is required before adding any drawable components, or else nothing will
    // show up. The default octree volume will be from (-1000, -1000, -1000) to (1000, 1000, 1000) in world coordinates; it
    // is also legal to place objects outside the volume but their visibility can then not be checked in a hierarchically
    // optimizing manner
    scene_->CreateComponent<Octree>();
    
    Node* planeNode = CreatePlane();
    
    Node* shipNode = CreateShip();
    shipNode->AddTag("ship");
    
    // Create a directional light to the world so that we can see something. The light scene node's orientation controls the
    // light direction; we will use the SetDirection() function which calculates the orientation from a forward direction vector.
    // The light will use default settings (white light, no shadows)
    Node* lightNode = scene_->CreateChild("DirectionalLight");
    lightNode->SetDirection(Vector3(0.6f, -1.0f, 0.8f)); // The direction vector does not need to be normalized
    auto* light = lightNode->CreateComponent<Light>();
    light->SetLightType(LIGHT_DIRECTIONAL);  
    
    // Create a scene node for the camera, which we will move around
    // The camera will use default settings (1000 far clip distance, 45 degrees FOV, set aspect ratio automatically)
    cameraNode_ = scene_->CreateChild("Camera");
    cameraNode_->CreateComponent<Camera>();

    // Set an initial position for the camera scene node above the plane
    cameraNode_->SetPosition(Vector3(0.0f, 10.0f, -15.0f));
    
    
    // Create two buttons to move the ship closer or further away from the camera
    auto* ui = GetSubsystem<UI>();
    UIElement* root = ui->GetRoot();
    auto* closerButton = 
        CreateButton(root, "closerButt", "CloserText", "Closer", 200, 550);
    auto* furtherButton = 
        CreateButton(root, "furtherButt", "FurtherText", "Further", 600, 550); 
    SubscribeToEvent(closerButton, E_CLICK, URHO3D_HANDLER(HelloWorld, HandleCloserClick));
    SubscribeToEvent(furtherButton, E_CLICK, URHO3D_HANDLER(HelloWorld, HandleFurtherClick));
}

/**
 * Creates a plane underneath the entire scene
 */
Node* HelloWorld::CreatePlane()
{
    auto* cache = GetSubsystem<ResourceCache>();
    
    Node* planeNode = scene_->CreateChild("Plane");
    planeNode->SetScale(Vector3(100.0f, 1.0f, 100.0f)); 
    auto* planeObject = planeNode->CreateComponent<StaticModel>();
    planeObject->SetModel(cache->GetResource<Model>("Models/Plane.mdl"));
    planeObject->SetMaterial(cache->GetResource<Material>("Materials/StoneTiled.xml")); 
    return planeNode;
}

/**
 * Creates the enemy ship to pursue
 */
Node* HelloWorld::CreateShip()
{
    auto* cache = GetSubsystem<ResourceCache>();
    
    Node* coneNode = scene_->CreateChild("Cone");
    coneNode->SetPosition(Vector3(0.0f, 10.0f, 10.0f));
    coneNode->SetScale(Vector3(10.0f, 10.0f, 10.0f));
    auto* coneObject = coneNode->CreateComponent<StaticModel>();
    coneObject->SetModel(cache->GetResource<Model>("Models/Cone.mdl"));
    coneObject->SetMaterial(cache->GetResource<Material>("Materials/torch_metal.xml")); 
    return coneNode;
}

void HelloWorld::MoveCamera(float timeStep)
{
    // Do not move if the UI has a focused element (the console)
    if (GetSubsystem<UI>()->GetFocusElement())
        return;

    auto* input = GetSubsystem<Input>();

    // Movement speed as world units per second
    const float MOVE_SPEED = 20.0f;
    // Mouse sensitivity as degrees per pixel
    const float MOUSE_SENSITIVITY = 0.05f;
    
    // Use this frame's mouse motion to adjust camera node yaw and pitch. 
    // Clamp the pitch between -90 and 90 degrees
    IntVector2 mouseMove = input->GetMouseMove();
    yaw_ += MOUSE_SENSITIVITY * mouseMove.x_;
    pitch_ += MOUSE_SENSITIVITY * mouseMove.y_;
    pitch_ = Clamp(pitch_, -90.0f, 90.0f);
    
    // Construct new orientation for the camera scene node from yaw and pitch. Roll is fixed to zero
    if (input->GetKeyDown(KEY_Q))
        cameraNode_->SetRotation(Quaternion(pitch_, yaw_, 0.0f));
    
    // Read WASD keys and move the camera scene node to the corresponding direction if they are pressed
    // Use the Translate() function (default local space) to move relative to the node's orientation.
    if (input->GetKeyDown(KEY_W))
        cameraNode_->Translate(Vector3::FORWARD * MOVE_SPEED * timeStep);
    if (input->GetKeyDown(KEY_S))
        cameraNode_->Translate(Vector3::BACK * MOVE_SPEED * timeStep);
    if (input->GetKeyDown(KEY_A))
        cameraNode_->Translate(Vector3::LEFT * MOVE_SPEED * timeStep);
    if (input->GetKeyDown(KEY_D))
        cameraNode_->Translate(Vector3::RIGHT * MOVE_SPEED * timeStep);
}

void HelloWorld::SetupViewport()
{
    auto* renderer = GetSubsystem<Renderer>();

    // Set up a viewport to the Renderer subsystem so that the 3D scene can be seen. We need to define the scene and the camera
    // at minimum. Additionally we could configure the viewport screen size and the rendering path (eg. forward / deferred) to
    // use, but now we just use full screen and default render path configured in the engine command line options
    SharedPtr<Viewport> viewport(new Viewport(context_, scene_, cameraNode_->GetComponent<Camera>()));
    renderer->SetViewport(0, viewport);
}
