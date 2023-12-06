#include "gtest/gtest.h"
#include "../src/Bench.h"
#include "../src/Monster.h"
#include "../src/definitions/Definitions.h"
// #include "../src/enum/MonsterType.h"


TEST(BenchTest, addMonster) {
    
    // ARRANGE
    Bench bench;
    Monster monster;

    // ACT
    monster.setName("Godzilla");

    // ASSERT
    EXPECT_NO_THROW( bench.addMonster(monster) );
    EXPECT_EQ(bench.getCurrent().getName(), "Godzilla");

}

TEST(BenchTest, reset) {
    
    // ARRANGE
    Bench bench;
    Monster monster;

    // ACT
    monster.setName("Godzilla");
    bench.addMonster(monster);
    bench.reset();

    // ASSERT
    EXPECT_EQ(bench.getDraftCount(), 0);

}