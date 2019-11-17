if Nickname == " " || Nickname == "" then Nickname = Player/Enemy
If Health == 0 then Health = 100
If Might == 0 then Might = 10
If Defence == 0 then Defence = 1
If Defence > 70 then Defence = 70
If CritChance == 0 then CritChance = 1
If CritBonus == 0 then CritBonus = 1
If Regen == 0 then Regen = 5

Defence = 10; // 10 - 10%, 70 - 70%
CritChance = 2; // 1 - 100% 2 - 50%, 3 - 33%, 4 - 25%, 5 - 20% etc
CritBonus = 2; // 1 - * 1, 2 - * 2, 3 - *3 etc

BattleSpeed = turbo/fast/normal/slow
ShowFullLog = true/false
SaveLogToFile = true/false
LogFileName = BattleLog (any file name)

ShowFullLog: 
// false - show: Might, CritMight, Health before attack, Health after attack
// true - show: Might, CritMight, Health before attack, Health after attack, Defence, Might after Defence, CritMight after Defence, Health before regen, Regen, Health after Regen