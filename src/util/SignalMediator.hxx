#ifndef SIGNALMEDIATOR_HXX_
#define SIGNALMEDIATOR_HXX_

#include <Singleton.hxx>
#include <Signal.hxx>
#include "../game/PowerGrid.hxx"

/**
 * @class SignalMediator
 * @brief Create signals and register callbacks here
 */

class SignalMediator : public Singleton<SignalMediator>
{
public:
  SignalMediator(){};
  ~SignalMediator(){};

  // Signals Map
  Signal::Signal<void(const MapNode &)> signalPlacePowerBuilding;
  Signal::Signal<void(const MapNode &)> signalPlaceBuilding;
  Signal::Signal<void(const MapNode &)> signalPlaceZone;
  Signal::Signal<void(MapNode *)> signalDemolish;

  // Signals Gameplay Managers
  Signal::Signal<void(const std::vector<PowerGrid> &)> signalUpdatePower;

  // Callback functions Map
  void registerCbPlaceZone(std::function<void(const MapNode &)> const &cb) { signalPlaceZone.connect(cb); }
  void registerCbPlacePowerBuilding(std::function<void(const MapNode &)> const &cb) { signalPlacePowerBuilding.connect(cb); }
  void registerCbPlaceBuilding(std::function<void(const MapNode &)> const &cb) { signalPlaceBuilding.connect(cb); }
  void registerCbDemolish(std::function<void(MapNode *)> const &cb) { signalDemolish.connect(cb); }

  // Callback functions Gameplay Managers
  
  void registerCbUpdatePower(std::function<void(const std::vector<PowerGrid> &)> const &cb) { signalUpdatePower.connect(cb); }
};

#endif