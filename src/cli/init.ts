import { writeFileSync } from "fs";
import chalk from "chalk";
import psync from "prompt-sync";

const prompt = psync();

interface SlyInfo {
	lua?: string;
	luarocks?: string;
	luarocks_deps?: Array<string>
}

const latestLVersion = "5.4.4";
const latestLrVersion = "3.9.2";

const doPrompt = (text: string, defValue: string = ""): string => {
	return prompt(
		chalk.bold(`${text} `)
		+ chalk.grey.bold(`(${defValue})`)
		+ chalk.bold(": "), defValue);
}

const promptInit = (): SlyInfo => {
	const luaVersion = doPrompt("lua version", latestLVersion);
	const luarocksVersion = doPrompt("luarocks version", latestLrVersion);

	return {
		lua: luaVersion,
		luarocks: luarocksVersion
	};
}

export { promptInit };
