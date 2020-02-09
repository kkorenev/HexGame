#pragma once

#include <Engine/Engine.hpp>
#include <Game/Layers/ButtonsLayer.hpp>

class Map;

class MapLayer : public Layer
{
public:
	MapLayer(const std::shared_ptr<Map>& map);

	virtual void update() override;
	virtual void render() override;
private:
	std::shared_ptr<Map> map;
	std::unordered_map<ResourseType, int> storageMap;
	std::vector<std::shared_ptr<Building>> buildings;

	std::vector<std::shared_ptr<Button>> buttonsBuildings;
	std::vector<std::shared_ptr<Button>> buttonsExtensionBuildings;
	std::vector<std::shared_ptr<Button>> buttonsResources;

	std::shared_ptr<View> viewGame;
	std::shared_ptr<View> viewUI;
	float speed = 2.f;

	bool defaultUI;
	bool extensionUI;
	bool transportingUI;

	bool treasuryEmpty;
	bool resourcePicked;
	float treasuryMoney;
	float totalUpkeep;
	double lastTime;
	ResourseType pickedResource;
	std::shared_ptr<Button> pickedBuilding;
	std::shared_ptr<Tile> selectedTile;
	std::shared_ptr<Tile> selectedExtensionTile;
	std::shared_ptr<Building> selectedBuilding;
	std::shared_ptr<Building> selectedExtensionBuilding;
	std::shared_ptr<Building> selectedTransportationBuilding;

	std::shared_ptr<Tile> pointedTile;

	std::shared_ptr<VertexArray> vao;
};
