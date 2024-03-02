WASI_SDK := "${HOME}/wasi-sdk-21.0"

.PHONY: clean help examples examples_native examples_wasm

help: ## Show this help
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

example_%.wasm:
	${WASI_SDK}/bin/clang -o example_$*.wasm examples/example_$*.c

example_%:
	clang -o example_$* examples/example_$*.c

clean: ## Delete previously built files
	rm -f example_*

examples_native: example_files example_input example_sound example_stdio example_video ## Build native examples

examples_wasm: example_files.wasm example_input.wasm example_sound.wasm example_stdio.wasm example_video.wasm ## Build wasm examples

examples: examples_native examples_wasm ## Build all examples (native & WASM)