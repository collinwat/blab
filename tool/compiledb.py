# Generates single, top-level compile_commands.json document.
# https://docs.platformio.org/en/latest/integration/compile_commands.html
import os

# Fail if the expected PlatformIO Import and SCons environment are unavailable
Import = globals()["Import"]
Import("env")

# Gets the PlatformIO created SCons Environment:
# https://scons.org/doc/2.3.6/HTML/scons-api/SCons.Script.SConscript%27.SConsEnvironment-class.html
env = globals()["env"]

# Replaces the PlatformIO COMPILATIONDB_PATH variable to point to the project
# directory rather each each build target directory.
env.Replace(COMPILATIONDB_PATH=os.path.join("$PROJECT_DIR", "compile_commands.json"))
