#include <Game/Map/Map.hpp>

#include <Game/Map/Tile.hpp>
#include <Game/Map/TerrainType.hpp>
#include <Game/Map/Utils.hpp>

Map::Map(const glm::ivec2& size) :
	size(size)
{
	tiles.resize(size.x * size.y);

	int a = 0;
	for (int x = 0; x < size.x; x++)
		for (int y = 0; y < size.y; y++)
		{
			tiles[a] = std::make_shared<Tile>(glm::ivec3(x, y, -x - y), TerrainType::Flatland);
			a++;
		}


}

const glm::ivec2& Map::getSize() const
{
	return size;
}

const std::shared_ptr<Tile>& Map::getTile(const glm::ivec3& coordinates) const
{
	for (const std::shared_ptr<Tile>& tile : tiles)
	{
		if (tile->getCoordinates() == coordinates)
		{
			return tile;
		}
	}

	if (coordinates.x < 0 && coordinates.x >= size.x && coordinates.y < 0 && coordinates.y >= size.y)
		return nullptr;

	return nullptr;
}

const std::vector<std::shared_ptr<Tile>>& Map::getNeighbors(const std::shared_ptr<Tile>& tile) const
{
	std::vector<std::shared_ptr<Tile>> vec;

	for (const glm::ivec3& offset : HexUtils::neighborsCoordinates)
	{
		auto t = getTile(glm::ivec3(tile->getCoordinates().x + offset.x, tile->getCoordinates().y + offset.y, tile->getCoordinates().z + offset.z));

		if (t != nullptr)
		{
			vec.push_back(t);
		}
	}

	return vec;
}