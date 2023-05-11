#include <gtest/gtest.h>
#include <limits.h>
#include <array>

#include <src/ArgumentParser.h>
#include <src/utils.h>

TEST(TestArgumentParser, RegisterFlag)
{
    ArgumentParser argParser;

    EXPECT_FALSE(argParser.IsFlagRegistered("MyFlag"));
    argParser.RegisterFlag("MyFlag");
    EXPECT_TRUE(argParser.IsFlagRegistered("MyFlag"));
}

TEST(TestArgumentParser, RegisterFlag_WhiteSpace)
{
    ArgumentParser argParser;

    argParser.RegisterFlag("My Flag");
    EXPECT_FALSE(argParser.IsFlagRegistered("My Flag"));
}

TEST(TestArgumentParser, RegisterOption)
{
    ArgumentParser argParser;

    argParser.RegisterOption("MyFlag");
    EXPECT_TRUE(argParser.IsOptionRegistered("MyFlag"));
}

TEST(TestArgumentParser, RegisterOption_WhiteSpace)
{
    ArgumentParser argParser;

    argParser.RegisterOption("My Flag");
    EXPECT_FALSE(argParser.IsOptionRegistered("My Flag"));
}

TEST(TestArgumentParser, Parse)
{
    ArgumentParser argParser;

    std::array<char *, 5> args = {
        "TestArgumentParser",
        "--flag",
        "--string=AaBbCcDd",
        "--number=42",
        "--float=4.2"};

    argParser.RegisterFlag("flag");
    argParser.RegisterOption("string");
    argParser.RegisterOption("number");
    argParser.RegisterOption("float");

    argParser.Parse(static_cast<int>(args.size()), args.data());

    EXPECT_FALSE(argParser.GetFlag("unregisteredflag"));
    EXPECT_TRUE(argParser.GetFlag("flag"));
    EXPECT_EQ(argParser.GetOptionAs<std::string>("string"), Utils::Funcs::ToLower("aabbccdd"));
    EXPECT_EQ(argParser.GetOptionAs<int>("number"), 42);
    EXPECT_EQ(argParser.GetOptionAs<float>("float"), 4.2f);
}

TEST(TestArgumentParser, Parse_InvalidArguments)
{
    ArgumentParser argParser;

    argParser.Parse(0, nullptr);
    argParser.Parse(42, nullptr);
}