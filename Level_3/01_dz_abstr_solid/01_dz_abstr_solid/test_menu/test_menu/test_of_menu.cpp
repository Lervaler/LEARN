#include "../../keeper.h"
#include "../../my_menu.h"


#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(Test_1, Test_create_punkt)
{
    EXPECT_ANY_THROW(My_menu punkt1(nullptr));
    std::string a = "punkt";
    My_menu punkt(a);
    auto name = punkt.get_name_my_menu();

    EXPECT_EQ("punkt", name);
}

TEST(Test_2, Test_create_ppunkt)
{
    My_menu punkt("punkt");
    My_menu ppunkt("ppunkt", punkt);
    auto name_punkt = punkt.get_name_my_menu();
    auto name_ppunkt = ppunkt.get_name_my_menu();

    EXPECT_EQ("punkt", name_punkt);
    EXPECT_EQ("ppunkt", name_ppunkt);
}

TEST(Test_3, Test_create_ppunkt_master)
{
    My_menu punkt("punkt");
    My_menu ppunkt("ppunkt", punkt);
    auto name_punkt = punkt.get_name_my_menu();
    auto master_ppunkt = ppunkt.get_master();

    EXPECT_EQ("punkt", master_ppunkt);
}

TEST(Test_4, Test_create_keeper)
{
    Keeper menu;
    auto menu_inside = menu.get_keeper();
    std::vector<My_menu> expect;

    EXPECT_EQ(menu_inside.data(), expect.data());
}

TEST(Test_5, Test_create_keeper_punkt)
{
    Keeper menu;
    menu.create_punkt("FILE");

    auto menu_inside = menu.get_keeper();
    auto exspect = menu_inside[0].get_name_my_menu();
    std::string name = "FILE";

    EXPECT_EQ(exspect, name);
}

TEST(Test_6, Test_create_keeper_ppunkt)
{
    Keeper menu;
    auto oblect = menu.create_punkt("FILE");
    menu.create_ppunkt("file", oblect);

    auto menu_inside = menu.get_keeper();
    auto exspect_punkt = menu_inside[0].get_name_my_menu();
    auto exspect_ppunkt = menu_inside[1].get_name_my_menu();

    std::string name_punkt = "FILE";
    std::string name_ppunkt = "file";

    EXPECT_EQ(exspect_punkt, name_punkt);
    EXPECT_EQ(exspect_ppunkt, name_ppunkt);
}

TEST(Test_7, Test_create_keeper_pppunkt)
{
    Keeper menu;
    auto oblect = menu.create_punkt("FILE");
    auto oblect_pp = menu.create_ppunkt("file", oblect);
    menu.create_ppunkt("file_file", oblect_pp);

    auto menu_inside = menu.get_keeper();
    auto exspect_punkt = menu_inside[0].get_name_my_menu();
    auto exspect_ppunkt = menu_inside[1].get_name_my_menu();
    auto exspect_pppunkt = menu_inside[2].get_name_my_menu();

    std::string name_punkt = "FILE";
    std::string name_ppunkt = "file";
    std::string name_pppunkt = "file_file";

    EXPECT_EQ(exspect_punkt, name_punkt);
    EXPECT_EQ(exspect_ppunkt, name_ppunkt);
    EXPECT_EQ(exspect_pppunkt, name_pppunkt);
}

















