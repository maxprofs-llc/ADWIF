/*  Copyright (c) 2013, Abdullah A. Hassan <voodooattack@hotmail.com>
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 *  OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 *  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace ADWIF
{
  class Player
  {
  public:
    // Intelligence, Wisdom, Charisma, Strength, Endurance, Dexterity, Agility
    enum Gender
    {
      Male,
      Female
    };

    Player(const std::shared_ptr<class Game> & game);

    std::shared_ptr<class Game> game() { return myGame.lock(); }
    void game(std::shared_ptr<class Game> & game) { myGame = game; }

    const std::string & name() const { return myName; }
    void name(const std::string & name) { myName = name; }

    Gender gender() const { return myGender; }
    void gender(Gender gender) { myGender = gender; }

    struct Race * race() const { return myRace; }
    void race(struct Race * race) { myRace = race; }

    struct Faction * faction() const { return myFaction; }
    void faction(struct Faction * faction) { myFaction = faction; }

    struct Profession * profession() const { return myProfession; }
    void profession(struct Profession * profession) { myProfession = profession; }

  private:
    std::weak_ptr<class Game> myGame;
    class Race * myRace;
    class Faction * myFaction;
    class Profession * myProfession;
    std::string myName;
    Gender myGender;
  };
}

#endif // PLAYER_HPP
