#!/usr/bin/env node
import { Command } from "commander";
import chalk from "chalk";

/* Getting package.json field */
import { readFile } from 'fs/promises';
const { version } = JSON.parse(
  await readFile(
    new URL('../package.json', import.meta.url)
  )
);

/* Init CLI */
const cli = new Command();

cli
  .name(process.argv[0])
  .description("A tool for building Lua into real Standalone Binary")
  .version(version, "-v --version");

cli.parse();

console.log(cli.opts());
