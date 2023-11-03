#include "MyBot.h"
#include <dpp/dpp.h>
#include <random>;
#include <fstream>;

const std::string    BOT_TOKEN    = "MTE2NTEyMDM4MDM4MjQ5MDY0NA.Gqrcx6.qM1jKllohP7QJtqpggZjE4f_kLib59HDAfAN8I";

long number = 0;
long highscore = 0;

int main()
{
	/* Create bot cluster */
	dpp::cluster bot(BOT_TOKEN);

	/* Output simple log messages to stdout */
	bot.on_log(dpp::utility::cout_logger());

	std::string hs_string;
	std::string readtxt;
	std::ifstream ReadHighscore("highscore.txt");
	while (getline(ReadHighscore, readtxt))
	{
		hs_string += readtxt;
	}
	highscore = std::stol(hs_string);
	ReadHighscore.close();


	std::string num_string;
	std::string readtxt2;
	std::ifstream ReadNum("number.txt");
	while (getline(ReadNum, readtxt2))
	{
		num_string += readtxt2;
	}
	number = std::stol(num_string);
	ReadNum.close();

	/* Handle slash command */
	bot.on_slashcommand([](const dpp::slashcommand_t& event) {
		if (event.command.get_command_name() == "ping") {
			event.reply("Pong!");
		}
	});

	bot.on_slashcommand([](const dpp::slashcommand_t& event) {
		if (event.command.get_command_name() == "8ball") {
			float random = rand() % 11;
			if (random <= 1)
			{
				event.reply("Yes");
			}
			if (random <= 2 and random > 1)
			{
				event.reply("No");
			}
			if (random <= 3 and random > 2)
			{
				event.reply("Idk");
			}
			if (random <= 4 and random > 3)
			{
				event.reply("Maybe");
			}
			if (random <= 5 and random > 4)
			{
				event.reply("100% Definitely Yes");
			}
			if (random <= 6 and random > 5)
			{
				event.reply("100% NOTTTTTT");
			}
			if (random <= 7 and random > 6)
			{
				event.reply("Prism gets to decide");
			}
			if (random <= 8 and random > 7)
			{
				event.reply("You are gay im not answering");
			}
			if (random <= 9 and random > 8)
			{
				event.reply("Go get a unique in aa before asking me again");
			}
			if (random <= 10 and random > 9)
			{
				event.reply("idk but i can tell u that kenny is gay");
			}
			else
			{
				event.reply("i did an oopsie woopsie it didnt work");
			}
		}
		});
	bot.on_slashcommand([](const dpp::slashcommand_t& event) {
		if (event.command.get_command_name() == "ppsize") {
			int random = rand() % 10;
			std::string size = "8";
			for (int i = 0; i < random; i++)
			{
				size += "=";
			}
			size += "3";
			int rand2 = rand() % 20;
			if (rand2 == 1)
			{
				event.reply("Your penis size is: " + size + "\n This is final, no changes, no trying again, thats your penis size");
			}
			else
			{
				event.reply("Your penis size is: " + size);
			}
		}
		});

	bot.on_slashcommand([](const dpp::slashcommand_t& event) {
		if (event.command.get_command_name() == "count") {
			int random = rand() % 10;
			int random2 = rand() % 100;
			if (random2 == 1)
			{
				int num1 = number + 1;
				std::string numstr1 = std::to_string(num1);
				int num2 = number + 2;
				std::string numstr2 = std::to_string(num2);
				int num3 = number + 3;
				std::string numstr3 = std::to_string(num3);
				int num4 = number + 4;
				std::string numstr4 = std::to_string(num4);
				int num5 = number + 5;
				std::string numstr5 = std::to_string(num5);
				int num6 = number + 6;
				std::string numstr6 = std::to_string(num6);
				int num7 = number + 7;
				std::string numstr7 = std::to_string(num7);
				int num8 = number + 8;
				std::string numstr8 = std::to_string(num8);
				int num9 = number + 9;
				std::string numstr9 = std::to_string(num9);
				number += 10;
				if (number > highscore)
				{
					highscore = number;
					std::ofstream HighscoreFile("highscore.txt");
					HighscoreFile << number;
					HighscoreFile.close();
				}
				std::string numberstr = std::to_string(number);
				std::ofstream NumberFile("number.txt");
				NumberFile << number;
				NumberFile.close();
				event.reply(numstr1 + ", " + numstr2 + ", " + numstr3 + ", " + numstr4 + ", " + numstr5 + ", " + numstr6 + ", " + numstr7 + ", " + numstr8 + ", " + numstr9 + ", " + numberstr + "\nWow I counted fast there, also i like children");
			}
			else
			{
				if (random < 9)
				{
					number += 1;
					if (number > highscore)
					{
						highscore = number;
						std::ofstream HighscoreFile("highscore.txt");
						HighscoreFile << number;
						HighscoreFile.close();
					}
					std::string numberstr = std::to_string(number);
					std::ofstream NumberFile("number.txt");
					NumberFile << number;
					NumberFile.close();
					event.reply(numberstr);
				}
				else
				{
					number += 2;
					std::string numberstr = std::to_string(number);
					event.reply(numberstr + ", oops, wrong number, gotta restart");
					number = 0;
					std::ofstream NumberFile("number.txt");
					NumberFile << number;
					NumberFile.close();
				}
			}
		}
		});

	bot.on_slashcommand([](const dpp::slashcommand_t& event) {
		if (event.command.get_command_name() == "viewnumber") {
			std::string numberstr = std::to_string(number);
			event.reply("The server's counting is at " + numberstr);
		}
		});

	bot.on_slashcommand([](const dpp::slashcommand_t& event) {
		if (event.command.get_command_name() == "highscore") {
			std::string highscorestr;
			std::string hstxt;
			std::ifstream ReadHighscore("highscore.txt");
			while (getline(ReadHighscore, hstxt))
			{
				highscorestr += hstxt;
			}
			event.reply("The server's highscore is " + highscorestr);
			ReadHighscore.close();
		}
		});

	/* Register slash command here in on_ready */
	bot.on_ready([&bot](const dpp::ready_t& event) {
		/* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
		if (dpp::run_once<struct register_bot_commands>()) {
			bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
		}
	});

	bot.on_ready([&bot](const dpp::ready_t& event) {
		/* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
		if (dpp::run_once<struct register_bot_commands>()) {
			bot.global_command_create(dpp::slashcommand("8ball", "get an answer", bot.me.id));
		}
		});

	bot.on_ready([&bot](const dpp::ready_t& event) {
		/* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
		if (dpp::run_once<struct register_bot_commands>()) {
			bot.global_command_create(dpp::slashcommand("ppsize", "find out your pp size", bot.me.id));
		}
		});

	bot.on_ready([&bot](const dpp::ready_t& event) {
		/* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
		if (dpp::run_once<struct register_bot_commands>()) {
			bot.global_command_create(dpp::slashcommand("count", "count higher", bot.me.id));
		}
		});

	bot.on_ready([&bot](const dpp::ready_t& event) {
		/* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
		if (dpp::run_once<struct register_bot_commands>()) {
			bot.global_command_create(dpp::slashcommand("viewnumber", "view what number the server is at", bot.me.id));
		}
		});

	bot.on_ready([&bot](const dpp::ready_t& event) {
		/* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
		if (dpp::run_once<struct register_bot_commands>()) {
			bot.global_command_create(dpp::slashcommand("highscore", "view the servers highscore", bot.me.id));
		}
		});

	/* Start the bot */
	bot.start(dpp::st_wait);

	return 0;
}
