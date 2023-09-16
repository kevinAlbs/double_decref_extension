# Add path to built extension to `PYTHONPATH`.
export PYTHONPATH=/home/kevin/code/cpython/KEVINALBS/double_decref/double_decref_extension/build/lib.linux-x86_64-cpython-313-pydebug
PYTHON=/home/kevin/code/cpython/debug/python
$PYTHON -c "import spam; spam.double_decref()"