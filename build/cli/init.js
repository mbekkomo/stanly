import chalk from "chalk";
import psync from "prompt-sync";
const prompt = psync();
const latestLVersion = "5.4.4";
const latestLrVersion = "3.9.2";
const doPrompt = (text, defValue = "") => {
    return prompt(chalk.bold(`${text} `)
        + chalk.grey.bold(`(${defValue})`)
        + chalk.bold(": "), defValue);
};
const promptInit = () => {
    const luaVersion = doPrompt("lua version", latestLVersion);
    const luarocksVersion = doPrompt("luarocks version", latestLrVersion);
    return {
        lua: luaVersion,
        luarocks: luarocksVersion
    };
};
export { promptInit };
