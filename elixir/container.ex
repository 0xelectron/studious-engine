defmodule Dockup.Container do
    defstruct [id: nil, name: nil, deployment_id: nil, image: nil, tag: nil, env_vars: [], command: [], args: [], init_containers: [], ports: [], cpu_request: nil, cpu_limit: nil, mem_request: nil, mem_limit: nil]
end

