from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension(
            name="spam",  # as it would be imported
                               # may include packages/namespaces separated by `.`

            sources=["spammodule.c"], # all sources are compiled into a single binary file
        ),
    ]
)